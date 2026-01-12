function fib(n) {
  if (n <= 0) {
    return 0;
  } else if (n === 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

function fibonacciIterative(n) {
  if (n <= 0) {
    return 0;
  } else if (n === 1) {
    return 1;
  }

  let a = 0; // f(0)
  let b = 1; // f(1)

  for (let i = 2; i <= n; i++) {
    let next = a + b; // f(i) = f(i-1) + f(i-2)
    a = b; // Обновляем f(i-2)
    b = next; // Обновляем f(i-1)
  }

  return b; // f(n)
}
