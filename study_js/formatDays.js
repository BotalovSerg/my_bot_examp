const dates = ["2026-01-10", "2026-01-11", "2026-01-12", "2026-01-13"];

const formattedDates = dates.map((dateStr) => {
  const date = new Date(dateStr);
  const day = String(date.getDate()).padStart(2, "0"); // 01, 02, ..., 10
  const month = String(date.getMonth() + 1).padStart(2, "0"); // Месяцы от 0, поэтому +1
  const weekday = date.toLocaleDateString("ru", { weekday: "short" }); // 'Сб', 'Вс', ...

  return `${day}.${month} ${weekday}`;
});

console.log(formattedDates); // ['10.01 Сб', '11.01 Вс', '12.01 Пн', '13.01 Вт']
