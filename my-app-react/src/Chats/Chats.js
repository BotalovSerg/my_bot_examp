import { useEffect } from "react";
import Header from "../Header/Header";
import { Link, useParams } from "react-router-dom";

export default function Chats() {
  const params = useParams();
  const { chatId } = params;
  useEffect(() => {
    const messagesEl = document.querySelector(".messages");

    const buttonEl = document.querySelector(".btn-send");
    const textareaEl = document.querySelector(".textarea");

    buttonEl.onclick = async function (event) {
      event.preventDefault();

      await fetch("http://localhost:3000/messages", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          text: textareaEl.value,
          author: { id: 1, name: "You" },
        }),
      });

      window.location.reload();
    };

    (async () => {
      const result = await fetch("http://localhost:3000/messages");
      const messages = await result.json();

      for (const message of messages) {
        const rootEl = document.createElement("div");
        rootEl.classList.add("message");
        rootEl.id = `message-${message.id}`;

        rootEl.innerHTML = `
        <p>${message.author.name}</p>
        <div>${message.text}</div>
        <button class="delete-button" id="delete-${message.id}">del</button>
        `;
        messagesEl.prepend(rootEl);
      }
      const buttons = document.querySelectorAll(".delete-button");
      buttons.forEach((button) => {
        button.onclick = async function () {
          const id = button.id.replace("delete-", "");

          await fetch(`http://localhost:3000/messages/${id}`, {
            method: "DELETE",
          });
        };
      });
    })();
  });

  return (
    <div>
      <Header />
      <main>
        <div className="wrapper">
          <div className="chats">
            <Link
              to="/chats/122"
              onClick={() => {
                console.log(chatId);
              }}
            >
              <div className={chatId === "122" ? "chats-active" : ""}>
                Sergey
              </div>
            </Link>
            <Link
              to="/chats/123"
              onClick={() => {
                console.log(chatId);
              }}
            >
              <div className={chatId === "123" ? "chats-active" : ""}>
                Volos
              </div>
            </Link>
            <Link
              to="/chats/124"
              onClick={() => {
                console.log(chatId);
              }}
            >
              <div className={chatId === "124" ? "chats-active" : ""}>
                Masha
              </div>
            </Link>
            <Link
              to="/chats/125"
              onClick={() => {
                console.log(chatId);
              }}
            >
              <div className={chatId === "125" ? "chats-active" : ""}>Dima</div>
            </Link>
            <Link
              to="/chats/126"
              onClick={() => {
                console.log(chatId);
              }}
            >
              <div className={chatId === "126" ? "chats-active" : ""}>Alex</div>
            </Link>
          </div>
          <div className="messages">
            <div className="message-form">
              <form action="">
                <textarea name="text" id="" className="textarea"></textarea>
                <button type="submit" className="btn-send">
                  Send message
                </button>
              </form>
            </div>
          </div>
        </div>
      </main>
    </div>
  );
}
