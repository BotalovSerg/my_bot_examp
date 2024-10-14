import { useState } from "react";
import "./Modal.css";

export default function Modal(props) {
  const { onClose, message } = props;
  const [value, setValue] = useState(message.text);
  const handleClick = () => {
    onClose();
  };
  return (
    <div className="modal-wrapper" onClick={handleClick}>
      <div className="modal-inner" onClick={(event) => event.stopPropagation()}>
        <div className="message-form-wrapper">
          <div className="message-form">
            <h3>Редактировать сообщение</h3>
            <form>
              <textarea
                name="text"
                className="textarea"
                value={value}
                onChange={(event) => setValue(event.target.value)}
              ></textarea>
              <button type="submit" className="btn-send">
                Save
              </button>
            </form>
          </div>
        </div>
      </div>
    </div>
  );
}
