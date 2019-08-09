let failAfter = time =>
  Js.Promise.make((~resolve as _, ~reject) =>
    Js.Global.setTimeout(() => reject(. Not_found), time) |> ignore
  );
let withTimeout = (promise, t) =>
  Js.Promise.race([|promise, failAfter(t)|]);