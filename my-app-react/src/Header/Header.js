import Button from "./Button";

export default function Header() {
  return (
    <header className="header">
      <Button title="My message"></Button>
      <Button title="Search friends"></Button>
      <Button title="Logout"></Button>
      <Button title="About"></Button>
    </header>
  );
}
