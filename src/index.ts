const addon = require('../build/Release/genomus_core_native');

interface IGenomusCoreNative {
    interpreter: (entry: string) => string;
}

const library: IGenomusCoreNative = addon;

export = library;

