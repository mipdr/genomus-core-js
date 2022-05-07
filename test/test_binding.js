const gm = require("../dist/binding.js");
const assert = require("assert");

assert(gm, "The expected function is undefined");

function testBasic()
{
    console.log(gm)
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");