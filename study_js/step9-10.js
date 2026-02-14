const artifacts = {
  A101: { type: "метеорит", year: 1890, exhibits: 15 },
  A102: { type: "луноход", year: 1973, exhibits: 20 },
  A103: { type: "скафандр", year: 1969, exhibits: 12 },
  A104: { type: "спутник", year: 1957, exhibits: 20 },
  A105: { type: "луноход", year: 1971, exhibits: 10 },
};

function analyzeArtifacts(artifacts) {
  let maxExhibits = 0;
  const countArtifacts = {};
  for (const key in artifacts) {
    console.log(
      `Артефакт ${key}: Тип - ${artifacts[key].type}, Год - ${artifacts[key].year}, Показы - ${artifacts[key].exhibits}`,
    );
    if (artifacts[key].exhibits >= maxExhibits) {
      maxExhibits = artifacts[key].exhibits;
    }
    if (artifacts[key].type in countArtifacts) {
      countArtifacts[artifacts[key].type] += 1;
    } else {
      countArtifacts[artifacts[key].type] = 1;
    }
  }
  console.log();

  console.log(`Артефакты с наибольшим количеством показов (количество показов ${maxExhibits}):`);
  for (const key in artifacts) {
    if (artifacts[key].exhibits === maxExhibits) {
      console.log(`${key}: Тип - ${artifacts[key].type}, Год - ${artifacts[key].year}`);
    }
  }
  console.log();
  console.log("Количество артефактов по типу:");
  for (const key in countArtifacts) {
    console.log(`${key}: ${countArtifacts[key]}`);
  }
}

// analyzeArtifacts(artifacts);

const data = {
  user: {
    id: 1,
    name: "Иван",
    age: 30,
    email: "ivan@example.com",
    address: {
      street: "Красная площадь",
      city: "Москва",
      postalCode: "101000",
    },
    hobbies: ["фотография", "путешествия", "чтение"],
    friends: [
      {
        id: 2,
        name: "Мария",
        age: 28,
        interests: ["живопись", "фотография"],
      },
      {
        id: 3,
        name: "Алексей",
        age: 32,
        interests: ["спорт", "музыка", "путешествия"],
      },
    ],
  },
  settings: {
    theme: "dark",
    notifications: {
      email: true,
      sms: false,
      push: true,
    },
    language: "ru",
  },
  activities: [
    {
      type: "work",
      date: "2024-09-21",
      duration: 120,
      details: {
        activityType: "работа",
        codeLines: 550,
      },
    },
    {
      type: "work",
      date: "2024-09-22",
      duration: 90,
      details: {
        activityType: "проведение урока",
        group: 24250,
      },
    },
    {
      type: "sleep",
      date: "2024-09-23",
      duration: 490,
      details: {
        with: "жена",
      },
    },
  ],
};

const obj = {};
obj.name = data.user.name;
obj.address = `${data.user.address.city}, ${data.user.address.street}`;

const friends = [];
for (let i = 0; i < data.user.friends.length; i++) {
  friends.push(data.user.friends[i].name);
}
obj.friends = friends;

const notifications = [];
for (const key in data.settings.notifications) {
  if (data.settings.notifications[key]) {
    notifications.push(key);
  }
}
obj.notifications = notifications;

const activitys = [];

for (let i = 0; i < data.activities.length; i++) {
  if (!activitys.includes(data.activities[i].type)) {
    activitys.push(data.activities[i].type);
  }
}
obj.activityTypes = activitys;
console.log(obj);
