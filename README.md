# container-zephir
Zephir utility for in-building a DI container as a PHP extension

# usage
```php
<?php

$container = new Container\Container();

$container->bind(DateTime::class, function ($container) {
	return new DateTime('now');
});

var_dump($container->make(DateTime::class));
```