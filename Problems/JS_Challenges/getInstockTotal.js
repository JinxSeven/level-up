const products = [
    { name: "Laptop", price: 999, quantity: 5, inStock: true },
    { name: "Mouse", price: 25, quantity: 0, inStock: false },
    { name: "Keyboard", price: 75, quantity: 10, inStock: true },
];

// Expected: (999 * 5) + (75 * 10) = 4995 + 750 = 5745
let inStockProdTotal = 0;
products
    .filter((prod) => prod.inStock)
    .forEach((prod) => {
        inStockProdTotal += prod.price * prod.quantity;
    });
console.log(inStockProdTotal);
