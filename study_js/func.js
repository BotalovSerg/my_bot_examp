// подключаем moment-timezone (в нодах n8n он есть)
const moment = require("moment-timezone");

function calculateCookingTime(currentTime) {
  const currentHour = currentTime.hour();

  if (currentHour >= 10 && currentHour < 18) {
    return 60; // 60 минут днем
  } else {
    return 90; // 90 минут вечером/утром
  }
}

// входные данные
const input = $("input").first().json.timeOrder;

// фиксированный часовой пояс
const TZ = "Asia/Tokyo";

// текущее время
const now = moment().tz(TZ);

// plannedTime
let plannedTime;

// === RULES ===

// 1. "ближайшее время"
if (input.toLowerCase().includes("ближайшее")) {
  plannedTime = now.clone().add(calculateCookingTime(now), "minutes");
}

// 2. "8 часов"
else if (input.includes("8")) {
  const eightAM = moment.tz(
    now.format("YYYY-MM-DD") + " 08:00",
    "YYYY-MM-DD HH:mm",
    TZ
  );
  const eightPM = moment.tz(
    now.format("YYYY-MM-DD") + " 20:00",
    "YYYY-MM-DD HH:mm",
    TZ
  );
  plannedTime = now.isBefore(eightAM) ? eightAM : eightPM;
}

// 3. конкретное время "HH:mm"
else if (/^\d{1,2}:\d{2}$/.test(input.trim())) {
  const [hh, mm] = input.split(":");
  plannedTime = moment.tz(
    now.format("YYYY-MM-DD") + ` ${hh}:${mm}`,
    "YYYY-MM-DD HH:mm",
    TZ
  );
  if (plannedTime.isBefore(now)) {
    plannedTime.add(1, "day");
  }
}

// 4. универсальный парсинг
else {
  const timeMatch = input.match(/(\d{1,2})[:\.]?(\d{2})?/);
  if (timeMatch) {
    let hh = parseInt(timeMatch[1]);
    let mm = timeMatch[2] ? parseInt(timeMatch[2]) : 0;

    if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59) {
      plannedTime = moment.tz(
        now.format("YYYY-MM-DD") + ` ${hh}:${mm.toString().padStart(2, "0")}`,
        "YYYY-MM-DD HH:mm",
        TZ
      );

      if (input.toLowerCase().includes("завтра") || plannedTime.isBefore(now)) {
        plannedTime.add(1, "day");
      }
    } else {
      plannedTime = now.clone().add(calculateCookingTime(now), "minutes");
    }
  } else {
    plannedTime = now.clone().add(calculateCookingTime(now), "minutes");
  }
}

// === CONDITIONS ===

let result = "ДА";
const currentCookingTime = calculateCookingTime(now);

// Проверка 1: plannedTime не должен быть раньше now + cookingTime
// (актуально только для "ближайшего времени" и fallback)
if (plannedTime.isBefore(now)) {
  result = "НЕТ";
}

// Проверка 2: plannedTime должен быть в рабочих часах 10:00-22:30
const plannedDate = plannedTime.format("YYYY-MM-DD");
const workStart = moment.tz(plannedDate + " 10:00", "YYYY-MM-DD HH:mm", TZ);
const workEnd = moment.tz(plannedDate + " 22:30", "YYYY-MM-DD HH:mm", TZ);

if (plannedTime.isBefore(workStart) || plannedTime.isAfter(workEnd)) {
  result = "НЕТ";
}

// Проверка 3: Для конкретного времени - должно быть не раньше now + cookingTime
// (только для случаев, когда пользователь указал конкретное время)
if (
  !input.toLowerCase().includes("ближайшее") &&
  plannedTime.isBefore(now.clone().add(currentCookingTime, "minutes"))
) {
  result = "НЕТ";
}

// === OUTPUT ===
return [
  {
    json: {
      result,
      plannedTime: plannedTime.format("YYYY-MM-DD HH:mm"),
      cookingTime: `${currentCookingTime} минут`,
      currentTime: now.format("YYYY-MM-DD HH:mm"),
    },
  },
];
