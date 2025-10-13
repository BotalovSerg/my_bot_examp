// подключаем moment-timezone (в нодах n8n он есть)
const moment = require('moment-timezone');

// входные данные
const input = $('input').first().json.timeOrder;

// фиксированный часовой пояс
const TZ = "Asia/Tokyo";

// текущее время
const now = moment().tz(TZ);

// рабочие часы
const WORK_START = moment.tz(now.format("YYYY-MM-DD") + " 10:00", "YYYY-MM-DD HH:mm", TZ);
const WORK_END = moment.tz(now.format("YYYY-MM-DD") + " 22:30", "YYYY-MM-DD HH:mm", TZ);

// plannedTime
let plannedTime;
let cookingTime; // Добавляем переменную для времени готовки

// === РАСЧЕТ ВРЕМЕНИ ГОТОВКИ ПО ТЕКУЩЕМУ ВРЕМЕНИ ===
const currentHour = now.hour();

// Определяем время готовки по текущему времени
if (currentHour >= 10 && currentHour < 18) {
    // Дневное время 10:00-17:59 → 60 минут
    cookingTime = 60;
} else if (currentHour >= 18 && currentHour < 22.5) { // 22.5 = 22:30
    // Вечернее время 18:00-22:29 → 90 минут
    cookingTime = 90;
} else {
    // Вне рабочих часов или утреннее время → 90 минут (по умолчанию)
    cookingTime = 90;
}

// === RULES ===

// 2. "ближайшее время"
if (input.toLowerCase().includes("ближайшее")) {
    plannedTime = now.clone().add(cookingTime, "minutes");
}

// 3. "8 часов"
else if (input.includes("8")) {
    const eightAM = moment.tz(now.format("YYYY-MM-DD") + " 08:00", "YYYY-MM-DD HH:mm", TZ);
    const eightPM = moment.tz(now.format("YYYY-MM-DD") + " 20:00", "YYYY-MM-DD HH:mm", TZ);

    if (now.isBefore(eightAM)) {
        plannedTime = eightAM;
    } else {
        plannedTime = eightPM;
    }
}

// 4. конкретное время "HH:mm"
else if (/^\d{1,2}:\d{2}$/.test(input.trim())) {
    const [hh, mm] = input.split(":");
    plannedTime = moment.tz(now.format("YYYY-MM-DD") + ` ${hh}:${mm}`, "YYYY-MM-DD HH:mm", TZ);

    // если время уже прошло → перенос на завтра
    if (plannedTime.isBefore(now)) {
        plannedTime.add(1, "day");
    }
}

// fallback: если не распознали → "ближайшее время"
else {
    // Ищем шаблоны времени в тексте
    const timeMatch = input.match(/(\d{1,2})[:\.]?(\d{2})?/);

    if (timeMatch) {
        let hh = parseInt(timeMatch[1]);
        let mm = timeMatch[2] ? parseInt(timeMatch[2]) : 0;

        // Валидация времени
        if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59) {
            plannedTime = moment.tz(now.format("YYYY-MM-DD") + ` ${hh}:${mm.toString().padStart(2, '0')}`, "YYYY-MM-DD HH:mm", TZ);

            // Обработка "завтра"
            if (input.toLowerCase().includes('завтра')) {
                plannedTime.add(1, 'day');
            }
            // Если время уже прошло сегодня и не указано "завтра" → перенос на завтра
            else if (plannedTime.isBefore(now)) {
                plannedTime.add(1, 'day');
            }
        } else {
            // Некорректное время → fallback
            plannedTime = now.clone().add(cookingTime, "minutes");
        }
    } else {
        // Время не найдено → fallback
        plannedTime = now.clone().add(cookingTime, "minutes");
    }
}

// === CONDITIONS ===

// проверка "не меньше чем через cookingTime минут"
let result = "ДА";
if (plannedTime.isBefore(now.clone().add(cookingTime, "minutes"))) {
    result = "НЕТ";
}

// проверка на рабочие часы
const checkDay = plannedTime.clone().format("YYYY-MM-DD");
const startCheck = moment.tz(checkDay + " 10:00", "YYYY-MM-DD HH:mm", TZ);
const endCheck = moment.tz(checkDay + " 22:30", "YYYY-MM-DD HH:mm", TZ);

if (plannedTime.isBefore(startCheck) || plannedTime.isAfter(endCheck)) {
    result = "НЕТ";
}

// === OUTPUT ===
return [
    {
        json: {
            result,
            plannedTime: plannedTime.format("YYYY-MM-DD HH:mm")
        }
    }
];
