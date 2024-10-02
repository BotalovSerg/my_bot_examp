const messagesEl = document.querySelector(".messages");

const messageList = JSON.parse(window.localStorage.getItem("messages") || []);
const buttonEl = document.querySelector(".btn-send");
const textareaEl = document.querySelector(".textarea")

for (const message of messageList) {
    const rootEl = document.createElement('div');
    rootEl.classList.add('message');

    rootEl.innerHTML = `
    <p>${message.author.name}</p>
    <div>${message.text}</div>
    `;

    // const authorEl = document.createElement('p');
    // authorEl.innerText = message.author.name;
    // rootEl.append(authorEl);

    // const textEl = document.createElement('div');
    // textEl.innerText = message.text;
    // rootEl.append(textEl);
    messagesEl.prepend(rootEl);
}

// buttonEl.addEventListener('click', function (event) {
//     event.preventDefault();
// });

buttonEl.onclick = function (event) {
    event.preventDefault();

    messageList.push(
        {
            id: messageList[messageList.length - 1].id + 1,
            text: textareaEl.value,
            author: { id: 1, name: 'You' }
        }
    );
    window.localStorage.setItem('messages', JSON.stringify(messageList));
    window.location.reload();
};