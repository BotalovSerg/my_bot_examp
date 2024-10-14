import { useEffect, useState } from "react";
import Header from "../Header/Header";
import { Link, useParams } from "react-router-dom";
import Modal from "../Modal/Modal";

export default function Chats() {
  const params = useParams();
  const { chatId } = params;
  const [messages, setMessages] = useState([]);
  const [value, setValue] = useState("");
  const [isModalOpen, setIsModalOpen] = useState(false);
  const [activeMessageId, setActiveMessageId] = useState();
  useEffect(() => {
    (async () => {
      try {
        const result = await fetch("http://localhost:3000/messages");
        const messages = await result.json();
        setMessages(messages);
      } catch (err) {
        console.log(err);
      }
    })();
  }, []);

  const handleSumit = async function (event) {
    event.preventDefault();

    const response = await fetch("http://localhost:3000/messages", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        text: value,
        author: { id: 1, name: "You" },
      }),
    });
    setValue("");
    const message = await response.json();
    setMessages([...messages, message]);
  };

  const handleDelete = async function (messageId) {
    await fetch(`http://localhost:3000/messages/${messageId}`, {
      method: "DELETE",
    });
    const delateMessageIdx = messages.findIndex(
      (message) => message.id === messageId
    );
    setMessages([
      ...messages.slice(0, delateMessageIdx),
      ...messages.slice(delateMessageIdx + 1, messages.length),
    ]);
  };

  return (
    <div>
      {isModalOpen && (
        <Modal
          onClose={() => setIsModalOpen(false)}
          message={messages.find((message) => message.id === activeMessageId)}
        />
      )}
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
            {messages.map((message) => (
              <div className="message" key={message.id}>
                <p>{message.author.name}</p>
                <div>{message.text}</div>
                <button
                  className="delete-button"
                  id={`delete-${message.id}`}
                  onClick={() => handleDelete(message.id)}
                >
                  del
                </button>
                <button
                  onClick={() => {
                    setActiveMessageId(message.id);
                    setIsModalOpen(true);
                  }}
                >
                  Редактировать
                </button>
              </div>
            ))}
            <div className="message-form">
              <form action="">
                <textarea
                  name="text"
                  className="textarea"
                  value={value}
                  onChange={(event) => setValue(event.target.value)}
                ></textarea>
                <button
                  type="submit"
                  className="btn-send"
                  onClick={handleSumit}
                >
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
