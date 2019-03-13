// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var Alert$BsReactNative = require("bs-react-native/src/alert.js");
var Style$BsReactNative = require("bs-react-native/src/style.js");
var Button$BsReactNative = require("bs-react-native/src/components/button.js");
var LinearGradient$ReasonExpo = require("reason-expo/src/LinearGradient.bs.js");

var component = ReasonReact.statelessComponent("App");

function onPress(param) {
  return Alert$BsReactNative.alert("alert", "yoyo", undefined, undefined, undefined, /* () */0);
}

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(Style$BsReactNative.style(/* :: */[
                                        Style$BsReactNative.flex(1),
                                        /* :: */[
                                          Style$BsReactNative.justifyContent(/* Center */2),
                                          /* :: */[
                                            Style$BsReactNative.alignItems(/* Center */2),
                                            /* [] */0
                                          ]
                                        ]
                                      ])), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                              ReasonReact.element(undefined, undefined, LinearGradient$ReasonExpo.make(/* array */[
                                        "#DD4B39",
                                        "#C62C19"
                                      ], undefined, undefined, undefined, Js_primitive.some(Style$BsReactNative.style(/* :: */[
                                                Style$BsReactNative.padding(/* Pt */Block.__(0, [12])),
                                                /* :: */[
                                                  Style$BsReactNative.borderRadius(12),
                                                  /* [] */0
                                                ]
                                              ])), /* array */[ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(Style$BsReactNative.style(/* :: */[
                                                          Style$BsReactNative.color(/* String */Block.__(0, ["white"])),
                                                          /* [] */0
                                                        ])), undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* array */["To get started, edit App.re!"]))])),
                              ReasonReact.element(undefined, undefined, Button$BsReactNative.make(undefined, undefined, undefined, onPress, undefined, "Go to list")(/* array */[]))
                            ]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (_jsProps) {
        return make(/* array */[]);
      }));

exports.component = component;
exports.onPress = onPress;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
