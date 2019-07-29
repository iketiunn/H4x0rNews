/* Hide it when scrolling down` */
open BsReactNative;
module Style = {
  open Style;
  let fab =
    style([
      /*  Should get backgroundColor to cover the comments */
      backgroundColor(String("#F7F5F8")),
      borderStyle(Solid),
      borderColor(String("black")),
      width(Pt(40.0)),
      height(Pt(40.0)),
      borderRadius(100.0),
      elevation(8.0),
      position(Absolute),
      bottom(Pt(2.0)),
      right(Pt(20.0)),
      /** For Android / iOS shadow */ elevation(2.0),
      shadowColor(String("#000000")),
      shadowOpacity(0.4),
      shadowRadius(1.0),
      shadowOffset(~height=1.0, ~width=0.0),
    ]);
  let arrow =
    style([
      marginLeft(Pt(12.0)),
      fontSize(Float(45.0)),
      color(String("black")),
      Transform.make(~scaleX=1.25, ()),
    ]);
};

/* let onPress = unit => unit; */
let component = ReasonReact.statelessComponent("BackToTopButton");
let make = (~onPress, _children) => {
  ...component,
  render: _self =>
    <TouchableOpacity onPress style=Style.fab>
      <Text style=Style.arrow value="^" />
    </TouchableOpacity>,
};