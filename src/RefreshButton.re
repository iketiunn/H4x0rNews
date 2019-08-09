/* Hide it when scrolling down` */
open BsReactNative;
let refreshImageSource =
  `Required(Packager.require("../assets/refresh.png"));

let component = ReasonReact.statelessComponent("RefreshButton");
let make = (~onPress, _children) => {
  ...component,
  render: _self =>
    <TouchableOpacity
      onPress style=AppStyle.RefreshButton.floatingActionButton>
      <Image style=AppStyle.Common.image source=refreshImageSource />
    </TouchableOpacity>,
};