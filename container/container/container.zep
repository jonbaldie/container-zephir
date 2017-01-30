namespace Container;

use Closure;
use Exception;
use InvalidArgumentException;
use ReflectionClass;
use ReflectionParameter;

class Container
{
    protected abstractions = [];
    protected bindings = [];
    protected concretions = [];
    protected instances = [];
    protected reflectors = [];

    public function make(class_name)
    {
        if is_string(class_name) && isset this->instances[class_name] {
            return this->instances[class_name];
        }

        var concrete, instance;

        let concrete = this->getConcrete(class_name);

        if this->isAbstract(class_name) {
            let instance = this->make(concrete);
        } else {
            let instance = this->build(concrete);
        }

        let this->instances[class_name] = instance;

        return instance;
    }

    public function build(class_name)
    {
        if is_string(class_name) && isset this->instances[class_name] {
            return this->instances[class_name];
        }

        if class_name instanceof Closure {
            return call_user_func(class_name, this);
        }

        var reflector, constructor, dependencies, parameters;

        let reflector = this->getReflector(class_name);

        if (! reflector->isInstantiable()) {
            throw new InvalidArgumentException();
        }

        let constructor = reflector->getConstructor();

        if is_null(constructor) {
            return new {class_name};
        }

        let dependencies = constructor->getParameters();
        let parameters = this->resolveDependencies(dependencies);

        return reflector->newInstanceArgs(parameters);
    }

    protected function getConcrete(class_name)
    {
        if is_string(class_name) && isset this->bindings[class_name] {
            return this->bindings[class_name];
        }

        return class_name;
    }

    protected function resolveDependencies(array dependencies)
    {
        var dependency, results, class_name;
        let results = [];

        for dependency in dependencies {
            let class_name = dependency->getClass();

            if is_null(class_name) {
                let results[] = this->resolvePrimitive(dependency);
            } else {
                let results[] = this->resolveClass(dependency);
            }
        }

        return results;
    }

    protected function resolvePrimitive(<ReflectionParameter> parameter)
    {
        if (parameter->isDefaultValueAvailable()) {
            return parameter->getDefaultValue();
        }

        throw new InvalidArgumentException();
    }

    protected function resolveClass(<ReflectionParameter> parameter)
    {
        var e;

        try {
            return this->make(parameter->getClass()->name);
        } catch Exception, e {
            if parameter->isOptional() {
                return parameter->getDefaultValue();
            }

            throw e;
        }
    }

    protected function getReflector(class_name)
    {
        if is_string(class_name) && isset this->reflectors[class_name] {
            return this->reflectors[class_name];
        }

        var reflector;
        let reflector = new ReflectionClass(class_name);
        let this->reflectors[class_name] = reflector;

        return reflector;
    }

    protected function isAbstract(class_name)
    {
        return ! this->getReflector(class_name)->isInstantiable();
    }

    public function bind(class_name, resolver)
    {
        if (is_a(resolver, class_name, false)) {
            let this->instances[class_name] = resolver;

            return;
        }

        if resolver instanceof Closure || is_a(resolver, class_name, true) {
            let this->bindings[class_name] = resolver;

            return;
        }

        throw new InvalidArgumentException();
    }
}