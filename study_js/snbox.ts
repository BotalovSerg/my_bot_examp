const o1: number = 20;
const o2: string = "20";
const o3: boolean = true;
const o4: null = null;
const o5: undefined = undefined;
const o6: any = 20;

function o7(a: number, b: string, c: boolean): string {
  return "abc";
}

const o8 = (one: number, two: string): number[] => {
  return [1, 2];
};

type User = {
  name: string;
  age: number;
  car?: { color: string };
};

interface User2 {
  name: string;
  age: number;
  car?: { color: string };
}

const o9: User = {
  name: "serg",
  age: 40,
  car: { color: "black" },
};

const o10: User2 = {
  name: "pena",
  age: 6,
};
