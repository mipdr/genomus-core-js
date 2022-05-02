const GenomusCore = require("../dist/binding.js");
const assert = require("assert");

assert(GenomusCore, "The expected function is undefined");

function testBasic()
{
    const result =  GenomusCore("hello");
    assert.strictEqual(result, "world", "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");