@echo off
set port=3000
explorer http://127.0.0.1:%port%
node ./check.js %port%