import { Link } from "react-router-dom";
import "./Button.css";

export default function Button(props) {
  const { title, href } = props;
  return (
    <Link to={href}>
      <button className="header-button">{title}</button>
    </Link>
  );
}
