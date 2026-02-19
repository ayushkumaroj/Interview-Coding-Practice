let userMethod = {
    greet(){
        return "Hello " + this.name;
    }
};

let user1 = Object.create(userMethod);
user1.name = "Ayush";

let user2 = Object.create(userMethod);
user2.name = "Rahul";

console.log(user1.greet()); // Hello Ayush
console.log(user2.greet()); // Hello Rahul

// let animal = {
//     type : "Animal"
// }

// let dog = Object.create(animal);
// dog.name = "Tommy";

// console.log(dog.name); // Tommy
// console.log(dog.type); // Animal

// let animal = {
//     type: "Animal",
//     speak() {
//         return "Some sound"
//     }
// };

// let dog = Object.create(animal);
// console.log(dog.type); // Animal
// console.log(dog.speak()); // Some sound

// let defaultSetting = {
//     theme: "light",
//     notification: true
// }

// let userSetting = {
//     theme: "dark"
// }

// let finalSettings = Object.assign({}, defaultSetting, userSetting);
// console.log(finalSettings) // { theme: 'dark', notification: true }

// let original = {name : "Ayush"};
// let copy = Object.assign({}, original);
// console.log(copy); // { name: 'Ayush' }

// let a = {
//     x : 1
// }

// let b = {
//     y : 2
// }

// let c = {
//     z : 3
// }

// let result = Object.assign(a, b, c);
// console.log(result); // { x: 1, y: 2, z: 3 }

// let a = {
//     x : 1
// }

// let b = {
//     y : 2
// }

// let result = Object.assign(a,b);
// console.log(result); // { x: 1, y: 2 }
// console.log(a); // { x: 1, y: 2 }



// let formData = {
//     name : "Ayush",
//     email : "",
//     password : "123456"
// };

// for(let [field, values] of Object.entries(formData)){
//     if(values === ""){
//         console.log(field + "is required");
//     }
// }
// // emailis required


// let user = {
//     name : "Ayush",
//     age : 21
// }

// for(let [key, values] of Object.entries(user)){
//     console.log(key, values);
// }
// // name Ayush
// // age 21












// let user = {
//     name : "Ayush",
//     age : 21
// };

// let entries = Object.entries(user);
// console.log(entries); 
// // [ [ 'name', 'Ayush' ], [ 'age', 21 ] ]


// let user = {
//     name : "Ayush",
//     age : 21,
//     city: "Delhi"
// };

// let values = Object.values(user);
// for(let value of values){
//     console.log(value);
// }
// // Ayush
// // 21
// // Delhi

// let user = {
//     name : "Ayush",
//     age : 21
// };

// let values = Object.values(user);

// for(let value of values){
//     console.log(value); // Ayush 21
// }

// let user = {
//     name : "Ayush",
//     age : 21,
//     city : "Delhi"
// };

// let values = Object.values(user);
// console.log(values); // [ 'Ayush', 21, 'Delhi' ]

// let user = {
//     name : "Ayush",
//     age : 21,
//     city : "Delhi"
// };

// let keys = Object.keys(user);
// for(let key of keys){
//     console.log(key + ":", user[key]);
// }
// name: Ayush
// age: 21
// city: Delhi

// let [user = {
//   name: "Ayush",
//   age: 21,
// };

// let keys = Object.keys(user);
// for (let key of keys) {
//   console.log(key); // name age
// }

// let user = {
//     name : "Ayush",
//     age : 21,
//     city : "Delhi"
// };

// let keys = Object.keys(user);
// console.log(keys); // [ 'name', 'age', 'city' ]

// let response = {
//     id: 1,
//     name: "Ayush",
//     email : "ayush@gmail.com"
// };

// let {name, email} = response;
// console.log(name); // Ayush
// console.log(email); // ayush@gmail.com

// let user = {
//     name : "Ayush"
// };

// let {name : userName } = user;
// console.log(userName); //Ayush

// let user = {
//     name : "Ayush",
//     age : 21
// }

// let { name } = user;
// console.log(name); //Ayush

// let name = User.name;
// let age = user.age;

// // let user = {
// //     name : "Ayush",
// //     age : 21
// // };

// let {name, age} = user;
// console.log(name); //Ayush
// console.log(age); //21

// let user = {
//     name : "Ayush",
//     age : 21
// };

// let updatedUser = {
//     ...user,
//     age : 22
// };

// console.log(updatedUser); // { name: 'Ayush', age: 22 }
// console.log(user); // { name: 'Ayush', age: 21 }
