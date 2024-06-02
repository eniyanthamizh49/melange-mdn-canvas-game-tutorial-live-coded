const path = require("path");

module.exports = {
  mode: "development",
  entry: {
    app: "./_build/default/output/App.js",
  },
  output: {
    path: path.resolve(__dirname, "dist"),
    filename: "bundle.js",
  },
};
