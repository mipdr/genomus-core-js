const gm = require("../build/index.js");
const assert = require("assert");

assert(gm, "The expected function is undefined");

console.log('Funciones exportadas: ')
Object.keys(gm).forEach(key => console.log(`${key}(1.0) = ${gm[key](1.0)}`))