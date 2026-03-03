// for (let i = 1; i < 10; i++) {
//   for (let j = 1; j < 10; j++) {
//     console.log(`${i} * ${j} = ${i * j}`);
//   }
// }

// const n = 7;
// let res = 1;
// for (let i = n; i > 0; i--) {
//   res *= i;
// }
// console.log(res);

// let n = -1234;
// let m = 234;
// let s = 0;

// for (let i = n; i < m; i++) {
//   s += i;
// }

// console.log(s);

// console.log("Четные числа:");
// for (let i = 0; i <= 20; i += 2) {
//   console.log(i);
// }
// console.log("Нечетные числа:");
// for (let i = 1; i < 20; i += 2) {
//   console.log(i);
// }

let n = 8;
let m = 11;
let flag = false
for (let i = n; i < m; i++) {
  if (i === 13) {
    flag = true;
    break   
  }
}
if (flag) {
  console.log("Число 13 обнаружено");  
} else {
  console.log("Число 13 не обнаружено"); 
}
let res = 0;
function sum(a,b){
  res = a + b
}