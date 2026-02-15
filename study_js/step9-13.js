const character = {
  name: "Name",
  class: "Class",
  level: 1,
  skills: [],
  setName(name) {
    this.name = name;
    return this;
  },
  setClass(className) {
    this.class = className;
    return this;
  },
  addSkill(skill) {
    this.skills.push(skill);
    return this;
  },
  levelUp() {
    this.level++;
    return this;
  },
  getSkillsStr() {
    if (this.skills.length === 0) {
      return "нет";
    }
    if (this.skills.length === 1) {
      return this.skills[0];
    }
    let str = "";
    for (let i = 0; i < this.skills.length; i++) {
      if (i === this.skills.length - 1) {
        str += `${this.skills[i]}`;
      } else {
        str += `${this.skills[i]}${i === this.skills.length - 2 ? " и " : ", "}`;
      }
    }
    return str;
  },
  getSummary() {
    return `Имя: ${this.name}, Класс: ${this.class}, Уровень: ${this.level}, Навыки: ${this.getSkillsStr()}`;
  },
};

const hero = character
  .setName("Химмель")
  .setClass("Воин")
  .addSkill("Уворот")
  .addSkill("Прямая атака")
  .addSkill("Геройская атака")
  .levelUp()
  .levelUp()
  .levelUp();

console.log(hero.getSummary());
