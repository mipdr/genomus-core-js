const addon = require('../build/Release/genomus_core_native');

interface IGenomusCoreNative {
    message: string;
}

const library: IGenomusCoreNative = addon;

export = library;

