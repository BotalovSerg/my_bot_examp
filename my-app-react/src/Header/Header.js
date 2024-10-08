import Button from "./Button";

export default function Header() {
  return (
    <header className="header">
      <Button title="My message" href="/chats"></Button>
      <Button title="Search friends" href="/frends"></Button>
      <Button title="Logout"  href="/logout"></Button>
      <Button title="Profile" href="/profile"></Button>
    </header>
  );
}
