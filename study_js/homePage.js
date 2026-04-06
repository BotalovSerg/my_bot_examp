const div = document.getElementById("product");

let products = ["Кофе", "Чай", "Сок", "Вода", "Яблоки"];

function pushItem(value) {
  products[products.length] = value;
}

let listEl = document.createElement("ol");

function renderList() {
  listEl.innerHTML = "";
  for (let i = 0; i < products.length; i++) {
    let itemEl = document.createElement("li");
    itemEl.textContent = products[i];
    listEl.append(itemEl);
  }
}
renderList();

let addItemEl = document.createElement("button");
addItemEl.textContent = "Добавить товар";
addItemEl.onclick = function () {
  let newItem = prompt("Введите название товара:");
  //   pushItem(newItem);
  products.push(newItem);
  renderList();
};

div.append(addItemEl, listEl);
