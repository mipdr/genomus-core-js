const addon = require('../build/Debug/genomus_core_native');

interface IGenomusCoreNative {
    message: string;
}

const library: IGenomusCoreNative = addon;

export = library;

