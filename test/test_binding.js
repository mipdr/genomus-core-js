const gm = require("../dist/binding.js");
const assert = require("assert");

assert(gm, "The expected function is undefined");

console.log(`gm.parameterMapper(1.0) = ${gm.parameterMapper(1.0)}`);
console.log("Tests passed- everything looks OK!");