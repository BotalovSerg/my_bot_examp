import "./Button.css";

export default function Button(props) {
  const { title } = props;
  return <button className="header-button">{title}</button>;
}
