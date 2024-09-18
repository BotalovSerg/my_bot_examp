function printNumbers(from, to) {
    let current = from; // Начинаем с числа from

    const timerId = setInterval(() => {
        console.log(current); // Выводим текущее число
        current++; // Увеличиваем текущее число

        // Если текущее число больше to, очищаем интервал
        if (current > to) {
            clearInterval(timerId);
        }
    }, 1000); // Интервал в 1000 миллисекунд (1 секунда)
}

printNumbers(5, 10);