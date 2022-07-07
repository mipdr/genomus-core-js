const gm = require("../build/index.js");

console.log('Funciones exportadas: ')
Object.keys(gm).forEach(key => console.log(' - ', key));


console.log(
    '\n\nINTERPRETER TEST\n',
    gm.interpreter('e_piano(n(0.1), m(0.2), a(0.3), i(0.4))')
);