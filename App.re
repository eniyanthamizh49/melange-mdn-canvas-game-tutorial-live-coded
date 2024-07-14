open Webapi;
open Webapi.Dom;
/* open Canvas; */

let fillColor = "#0095DD";

switch (Document.getElementById("myCanvas", Dom.document)) {
| Some(canvas) =>
  let canvasWidth = canvas |> Canvas.CanvasElement.width;
  let canvasHeight = canvas |> Canvas.CanvasElement.height;
  let x = ref(canvasWidth / 2);
  let y = ref(canvasHeight - 30);
  let dx = 2;
  let dy = (-2);

  let ctx = Canvas.CanvasElement.getContext2d(canvas);

  let drawBall = () => {
    open Canvas.Canvas2d;
    ctx |> beginPath;
    ctx
    |> arc(
         ~x=float(x^),
         ~y=float(y^),
         ~r=10.,
         ~startAngle=0.,
         ~endAngle=Js.Math._PI *. 2.,
         ~anticw=false,
       );
    Canvas.Canvas2d.setFillStyle(ctx, String, fillColor);
    ctx |> Canvas.Canvas2d.fill;
    ctx |> Canvas.Canvas2d.closePath;
  };

  let draw = () => {
    open Canvas.Canvas2d;
    ctx->clearRect(
      ~x=0.,
      ~y=0.,
      ~w=canvasWidth |> float,
      ~h=canvasHeight |> float,
    );
    drawBall();
    x := x^ + dx;
    y := y^ + dy;
  };

  let startGame = () => {
    let _ = Js.Global.setInterval(~f=draw, 10);
    ();
  };

  switch (document |> Document.getElementById("runButton")) {
  | None => ()
  | Some(runButton) =>
    runButton
    |> Dom.Element.addClickEventListener(_ => {
         startGame();
         runButton |> Dom.Element.setAttribute("disabled", "true");
       })
  };

| None => ()
};
