console.log("Start");

setTimeout(() => {
  console.log("Timeout");
}, 0);

Promise.resolve().then(() => {
  console.log("Promise");
});

console.log("End");

/*
Start
End
Promise
Timeout
*/

// console.log("Start");

// Promise.resolve().then(() => {
//   console.log("Promise");
// });

// console.log("End");

// /* Output
// Start
// End
// Promise
// */

// console.log("A");
// setTimeout(() => {
//   console.log("B");
// }, 1000);
// console.log("C");

// /* Output
// A
// C
// B
// */

// console.log("Start");
// setTimeout(() => {
//   console.log("Async Task");
// }, 0);
// console.log("End");

// /* Output
// Start
// End
// Async Task
// */

// fetch("https://api.example.com")
//   .then((res) => res.json())
//   .then((data) => {
//     console.log(data);
//   })
//   .catch((err) => console.log(err));

// // fetch("https://api.example.com", {
// //   method: "POST",
// //   body: JSON.stringify({ name: "Ayush" }),
// //   headers: {
// //     "Content-Type": "application/json",
// //   },
// // });

// console.log("Start");

// fetch("https://jsonplaceholder.typicode.com/todos/1")
//   .then((res) => res.json())
//   .then((data) => console.log(data));

// console.log("End");

// /*Output
// Start
// End
// (data later)
// */

// fetch("https://api.example.com/data")
//   .then((res) => res.json())
//   .then((data) => console.log(data));

// const os = require("os");
// console.log(os.platform());

// // const http = require("http");
// // const server = http.createServer((req, res) => {
// //   res.end("Hello World");
// // });
// // server.listen(3000);

// const fs = require("fs");
// fs.writeFile("file.txt", "Hello", (err) => {
//   console.log("Done");
// });

// const fs = require("fs");
// fs.readFile("file.txt", "utf8", (err, data) => {
//   console.log(data);
// });

// fetch("https://api.example.com")
//   .then((res) => {
//     if (!res.ok) {
//       throw new Error("Error");
//     }
//     return res.json();
//   })
//   .then((data) => console.log(data))
//   .catch((err) => console.log(err));

// fetch("https://api.example.com", {
//   method: "POST",
//   body: JSON.stringify({ name: "Ayush" }),
//   headers: {
//     "Content-Type": "application/json",
//   },
// });

// async function fetchData() {
//   console.log("Fetching...");

//   let res = await fetch("https://jsonplaceholder.typicode.com/todos/1");
//   let data = await res.json();

//   console.log(data);
// }
// fetchData();

/* Output
Fetching...
(data after delay)
*/

// console.log("Start");

// fetch("https://jsonplaceholder.typicode.com/todos/1")
//   .then((res) => res.json())
//   .then((data) => console.log(data));

// console.log("End");

/* Output
Start
End
(data later)
*/

// async function getData() {
//   let response = await fetch("https://api.example.com");
//   let data = await response.json();
//   console.log(data);
// }

// fetch("https://api.example.com")
// .then(response => response.json())
// .then(data => console.log(data));

// functio
// n delayedMessage() {
//   setTimeout(() => {
//     console.log("Hello after delay");
//   }, 1500);
// }
// delayedMessage();

// Output: Hello after delay
// let count = 0;
// let id = setInterval(() => {
//   count++;
//   console.log(count);

//   if (id === 3) {
//     clearInterval(id);
//   }
// }, 1000);

// /* Output
// 1
// 2
// 3
// */

// setInterval(() => {
//   console.log("Tick");
// }, 1000);

// /* Output
// Tick
// Tick
// Tick..
// */

// console.log("Start");
// setTimeout(() => {
//   console.log("After 2 sec");
// }, 2000);

// console.log("End");
// /* Output
// Start
// End
// After 2 Sec
// */

// let id = setTimeout(() => {
//   console.log("Will not run");
// }, 2000);
// clearInterval(id);

// setInterval(() => {
//   console.log("Running...");
// }, 1000);

// // setTimeout(() => {
// //   console.log("Hello");
// // }, 2000);

// document.addEventListener("click", () => {
//   console.log("User clicked");
// });

// // console.log("Fetching...");

// // fetch("https://jsonplaceholder.typicode.com/todos/1")
// //   .then((res) => res.json())
// //   .then((data) => console.log(data));

// // console.log("Done");

// // /*Output
// // Fetching...
// // Done
// // { userId: 1, id: 1, title: 'delectus aut autem', completed: false }
// // */

// /* Output
// Start
// End
// From Web API
// */

// // document.addEventListener("click", () => {
// //   console.log("Clicked");
// // });

// // // setTimeout(() => {
// // //   console.log("Hello");
// // // }, 1000);

// // fetch("https://api.example.com")
// // .then(res => res.json());
// // .then(data => console.log(data));

// // const fs = require("fs");
// // fs.writeFileSync("file.txt", "Hello");

// // // document.body.innerHTML = "Hello";

// // // // console.log("Start");

// // // // setTimeout(() => {
// // // //   console.log("From Runtime");
// // // // }, 1000);

// // // console.log("End");

// /* Output
// Start
// End
// From Runtime
// */

// // setTimeout(() => {
// //     console.log("Hello");
// // }, 1000);

// // // console.log("Hello"

// // // function add(a, b) {
// // //   return a + b;
// // // }
// // // console.log(add(2, 3));
// // // Output: 5

// // // let a = 5;
// // // let b = 10;
// // // console.log(a+b);
// // // //Output: 15

// // // console.log("Hello World");

// // function delay() {
// //   return new Promise((resolve) => {
// //     setTimeout(() => {
// //       resolve("Finished");
// //     }, 2000);
// //   });
// // }

// // async function run() {
// //   console.log("Start");
// //   let res = await delay();
// //   console.log(res);
// //   console.log("End");
// // }

// // run();

// /* Output
// Start
// (after delay)
// Finished
// End
// */

// // let promise = new Promise((resolve) => {
// //   setTimeout(() => {
// //     resolve("Done");
// //   }, 2000);
// // });

// // console.log("Start");

// // promise.then((res) => {
// //   console.log(res);
// // });
// // console.log("End");

// // /* Output
// // Start
// // End
// // Done
// // */

// // let promise = new promise((resolve) => {
// //     setTimeout(() => {
// //         resolve("Done")
// //     }, 2000)
// // })

// // console.log("Start");

// // promise.then((res) => {
// //     console.log(res);
// // });
// // console.log("End");
// // /* Output
// // Start
// // End
// // Done
// // */

// // function fetchData(){
// //     setTimeout(()=>{
// //         console.log("Data received");
// //     }, 2000);
// // }

// // console.log("Request sent");
// // fetchData();
// // console.log("Continue execution");

// // /* Output
// // Request sent
// // Continue execution
// // Data received
// // */

// // console.log("Start");

// // setTimeout(() => {
// //   console.log("Async Task");
// // }, 2000);

// // console.log("End");

// // /* Output
// // Start
// // End
// // Async Task
// // */

// // setTimeout(() => {
// //     console.log("Hello");
// // }, 2000);
