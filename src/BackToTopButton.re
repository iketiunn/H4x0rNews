/* Hide it when scrolling down` */
open BsReactNative;
module Style = {
  open Style;
  let fab =
    style([
      /*  Should get backgroundColor to cover the comments */
      backgroundColor(String("transparent")),
      marginLeft(Auto),
      marginRight(Pt(15.0)),
      elevation(8.0),
      position(Absolute),
      bottom(Pt(0.0)),
      right(Pt(15.0)),
    ]);
  let arrow =
    style([
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