import unittest.mock
import functools


def lru_cache(*args, **kws):
    if len(args) == 1 and callable(args[0]) and not kws:
        func = args[0]

        @functools.wraps(func)
        def inner(*func_arg, **func_kws):
            res = func(*func_arg, **func_kws)
            return res

        return inner
    else:
        maxsize = kws.get("maxsize", 1000)

        def decorator_func(func):
            @functools.wraps(func)
            def wrapper_func(*func_arg, **func_kws):
                if maxsize:
                    print("maxsize", maxsize)
                result = func(*func_arg, **func_kws)
                return result

            return wrapper_func

        return decorator_func


@lru_cache
def sum(a: int, b: int) -> int:
    return a + b


@lru_cache
def sum_many(a: int, b: int, *, c: int, d: int) -> int:
    return a + b + c + d


@lru_cache(maxsize=3)
def multiply(a: int, b: int) -> int:
    return a * b


if __name__ == "__main__":

    sum(1, 2)
    sum(3, 4)
    multiply(1, 2)
    multiply(3, 4)
    sum_many(1, 2, c=3, d=4)

    assert sum(1, 2) == 3
    assert sum(3, 4) == 7

    assert multiply(1, 2) == 2
    assert multiply(3, 4) == 12

    assert sum_many(1, 2, c=3, d=4) == 10

    mocked_func = unittest.mock.Mock()
    mocked_func.side_effect = [1, 2, 3, 4]

    decorated = lru_cache(maxsize=2)(mocked_func)
    assert decorated(1, 2) == 1
    assert decorated(1, 2) == 1
    assert decorated(3, 4) == 2
    assert decorated(3, 4) == 2
    assert decorated(5, 6) == 3
    assert decorated(5, 6) == 3
    assert decorated(1, 2) == 4
    assert mocked_func.call_count == 4
