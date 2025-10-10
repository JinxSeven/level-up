const users = [
    { name: "Alice", active: true },
    { name: "Bob", active: false },
    { name: "Charlie", active: true },
];

// map transforms what it returns into an array
console.log(users.filter((user) => user.active === true).map(user => user.name))