// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function failAfter(time) {
  return new Promise((function (param, reject) {
                setTimeout((function (param) {
                        return reject(Caml_builtin_exceptions.not_found);
                      }), time);
                return /* () */0;
              }));
}

function withTimeout(promise, t) {
  return Promise.race(/* array */[
              promise,
              failAfter(t)
            ]);
}

exports.failAfter = failAfter;
exports.withTimeout = withTimeout;
/* No side effect */
