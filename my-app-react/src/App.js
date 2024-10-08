import { useEffect } from "react";
import { Route, Routes, BrowserRouter } from "react-router-dom";
import "./App.css";
import Chats from "./Chats/Chats";
import Profile from "./Profile/Profile";
import Frends from "./Frends/Frends";

export default function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="" element={<Chats />}></Route>
        <Route path="/chats" element={<Chats />}></Route>
        <Route path="/chats/:chatId" element={<Chats />}></Route>
        <Route path="/frends" element={<Frends />}></Route>
        <Route path="/profile" element={<Profile />}></Route>
      </Routes>
    </BrowserRouter>
  );
}
