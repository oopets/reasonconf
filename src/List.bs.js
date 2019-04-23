// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Data$ReactHooksTemplate = require("./Data.bs.js");

var places = Data$ReactHooksTemplate.Resto[/* places */0];

var imgStyle = {
  height: "80px",
  margin: "10px",
  width: "auto"
};

function getElements(places, term) {
  return Belt_Array.map(Data$ReactHooksTemplate.Resto[/* search */1](places, term), (function (p) {
                var match = p[/* img */3][/* attrUrl */2];
                return React.createElement("li", {
                            key: p[/* id */0]
                          }, React.createElement("img", {
                                style: imgStyle,
                                title: match !== undefined ? match : "No attribution",
                                src: p[/* img */3][/* url */0]
                              }), p[/* name */1]);
              }));
}

var headerStyle = {
  color: "#444444",
  fontSize: "20px"
};

function List(Props) {
  var term = Props.term;
  var elements = getElements(places, term);
  return React.createElement(React.Fragment, undefined, React.createElement("span", undefined, React.createElement("h3", {
                      style: headerStyle
                    }, "My Lovely Restaurant List. Total: ", String(elements.length))), React.createElement("ul", undefined, elements));
}

var make = List;

exports.places = places;
exports.imgStyle = imgStyle;
exports.getElements = getElements;
exports.headerStyle = headerStyle;
exports.make = make;
/* react Not a pure module */
