//web pack modules
open Webapi;
open Webapi.Dom;
/* open Canvas; */
// color fill 
let fillColor = "#0095DD";

switch (Document.getElementById("myCanvas", Dom.document)) {
| Some(canvas) =>
  // canvas properties and ball position 
  let canvasWidth = canvas |> Canvas.CanvasElement.width;
  let canvasHeight = canvas |> Canvas.CanvasElement.height;
  let x = ref(canvasWidth / 2);
  let y = ref(canvasHeight - 30);
  let dx = 2;
  let dy = (-2);
  let ballRadius = 10.;
// 2d context
  let ctx = Canvas.CanvasElement.getContext2d(canvas);
// drawing the ball
  let drawBall = () => {
    open Canvas.Canvas2d;
    ctx |> beginPath;
    ctx
    |> arc(
         ~x=float(x^),
         ~y=float(y^),
         ~r=ballRadius,
         ~startAngle=0.,
         ~endAngle=Js.Math._PI *. 2.,
         ~anticw=false,
       );
    Canvas.Canvas2d.setFillStyle(ctx, String, fillColor);
    ctx |> Canvas.Canvas2d.fill;
    ctx |> Canvas.Canvas2d.closePath;
  };
// Animating the bell 
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
// starting the game 
  let startGame = () => {
    let _ = Js.Global.setInterval(~f=draw, 10);
    ();
  };
// adding event listener 
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
