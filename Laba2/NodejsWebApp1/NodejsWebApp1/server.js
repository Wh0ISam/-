< !DOCTYPE html >
< !--
    To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
    <html>
        <head>
            <title>Визуализатор bitmex</title>
            <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
                <body>
                    <script src="/socket.io/socket.io.js"></script>
                    <script src="https://code.jquery.com/jquery-1.11.1.js"></script>
                    <script>
                        $(function () {
            var sell_thread = [];
                        var buy_thread = [];
                        var socket = io();
                        var timec = null;
            socket.on('trade', function(data){
                for (var i = 0; i < data.length; i++) {
                    if (data[i].side === "Buy") {
                            app.buy_trades++;
                        app.buy_vol_per_min = app.buy_vol_per_min + data[i].size;
                    } else {
                            app.sell_trades++;
                        app.sell_vol_per_min = app.sell_vol_per_min + data[i].size;
                    }
                    if (app.min_min == 0 || app.min_min > data[i].price) {
                            app.min_min = data[i].price;
                        }
                    if ( app.max_min < data[i].price) {
                            app.max_min = data[i].price;
                        }
                    }
                    app.buffer = app.buffer.concat(data);
                if (app.buffer.length > 100) {
                            app.buffer.splice(0, app.buffer.length - 100);
                        }
                        $('title').html(app.buffer[app.buffer.length-1].price);
                        kindles.drawTrade(data);
                    });
                    var control_count = 0;
            setInterval(function () {
                            $("#sell-thread").empty();
                        $("#buy-thread").empty();
                        
                        app.redrawVolPerMin();
                        
                        var buffer = [].concat(app.buffer);
                    for (var i = 0; i < buffer.length; i++) {
                        var b = 0;
                        var s = 0;
                        if (buffer[i].side == "Buy") {
                            b = (buffer[i].size * 100 / app.max);
                        } else {
                            s = (buffer[i].size * 100 / app.max);
                        }
                        $("#sell-thread").append("<div style='position: absolute; top: 0px; left:" + i + "px;display: inline-block;background-color:red; width: 1px; height: "+s+"px;'></div>");
                        $("#buy-thread").append("<div style='position: absolute; bottom: 0px; left:" + i + "px; display: inline-block;background-color:green; width: 1px; height: "+b+"px;'></div>");
                    }
                    if (buffer) {
                        if (!kindles.last_kindle) {
                            kindles.last_kindle = {
                                open: kindles.data[0].close,
                                close: app.buffer[app.buffer.length - 1].price,
                                low: app.buffer[app.buffer.length - 1].price,
                                high: app.buffer[app.buffer.length - 1].price,
                            };
                        }
                        var price = buffer[buffer.length-1].price;
                        if (price > kindles.last_kindle.high) {
                            kindles.last_kindle.high = price;
                        }
                        if (price < kindles.last_kindle.low) {
                            kindles.last_kindle.low = price;
                        }
                        kindles.last_kindle.close = price;
                    }
                    kindles.redraw();
            }, 500);
            var t = 0;
            socket.on('orderBookL2', function(data){
                
                if (!data){
                    return ;
                    }
                    kindles.orderBookL2 = [].concat(data);
                    kindles.redraw();
                });
            socket.on('kindles', function(data){
                            kindles.data = data;
                        kindles.redraw();
                    });
            socket.on('tradeBin5m', function(data){
                            kindles.data.splice(kindles.data.length - 1, 1);
                        kindles.data = data.concat(kindles.data);
                kindles.last_kindle_vol = {};
                kindles.last_kindle = {
                            open: app.buffer[app.buffer.length-1].price,
                        close: app.buffer[app.buffer.length-1].price,
                        low: app.buffer[app.buffer.length-1].price,
                        high: app.buffer[app.buffer.length-1].price,
                    };
                    kindles.redraw();
                });
               
            window.app = {
                            kindles: [],
                        max: 0,
                        buffer: [],
                        buy_vol: 0,
                        sell_vol: 0,
                        volums_per_min : [],
                        buy_vol_per_min : 0,
                        sell_vol_per_min : 0,
                        max_min: 0,
                        min_min: 0,
                        buy_trades: 0,
                        sell_trades: 0,
                init: function () {
                            app.canvas2 = document.getElementById("volumspermin");
                        app.ctx2 = app.canvas2.getContext('2d');
                        app.canvas2.width = app.canvas2.offsetWidth;
                        app.canvas2.height = app.canvas2.offsetHeight;
                       
    
                       
                    setInterval(function () {
                            app.volums_per_min.push({
                                buy: app.buy_vol_per_min,
                                sell: app.sell_vol_per_min,
                                max: app.max_min,
                                min: app.min_min,
                                buy_trades: app.buy_trades,
                                sell_trades: app.sell_trades
                            });
                        app.max_min = 0;
                        app.min_min = 0;
                         app.buy_vol_per_min = 0;
                         app.sell_vol_per_min = 0;
                         app.sell_trades = 0;
                         app.buy_trades = 0;
                        if (app.volums_per_min.length >130) {
                            app.volums_per_min.splice(0, app.volums_per_min.length - 130);
                        }
                        app.redrawVolPerMin();
                    },  5 * 60000);
                    $('#range_vol').on('input', function () {
                            $('#range_vol_val').html($(this).val());
                        app.redrawVolPerMin();
                    });
                    $('#range_levels').on('input', function () {
                            $('#range_levels_val').html($(this).val());
                        app.redrawVolPerMin();
                    });
                    $('#bgcolor').on('change', function () {
                            $('body').toggleClass('night_style');
                        });
                    },
                redrawVolPerMin: function () {
                    var volums = app.volums_per_min.concat([{
                            buy: app.buy_vol_per_min,
                        sell: app.sell_vol_per_min,
                        max: app.max_min,
                        min: app.min_min,
                        buy_trades: app.buy_trades,
                        sell_trades: app.sell_trades
                    }]);
                var max = 0;
                var min_price = 0;
                var max_price = 0;
                var volums_sr = [];
                var volums_sr_summ = [];
                var max_trades = 0;
                    for (var i = 0; i < volums.length; i++) {
                        var buy_summ = 0;
                        var sell_summ = 0;
                        var summ = 0;
                        for (var k = 0; k < $('#range_vol').val() && k <= i; k++) {
                            buy_summ += volums[i - k].buy;
                        sell_summ += volums[i-k].sell;
                        summ += buy_summ+sell_summ;
                    }
                    volums_sr.push(buy_summ / (buy_summ + sell_summ));
                    volums_sr_summ.push(summ);
                        if (max < volums[i].buy) {
                            max = volums[i].buy;
                        }
                        if (max < volums[i].sell) {
                            max = volums[i].sell;
                        }
                        if (min_price == 0 || min_price > volums[i].min) {
                            min_price = volums[i].min;
                        }
                        if (max_price < volums[i].max) {
                            max_price = volums[i].max;
                        }
                        if (max_trades < volums[i].sell_trades) {
                            max_trades = volums[i].sell_trades;
                        }
                        if (max_trades < volums[i].buy_trades) {
                            max_trades = volums[i].buy_trades;
                        }
                    }
                    if (max < app.buy_vol_per_min) {
                            max = app.buy_vol_per_min;
                        }
                    if (max < app.sell_vol_per_min) {
                            max = app.sell_vol_per_min;
                        }
                        $('#max_buy_vol').html(max);
                        app.ctx2.clearRect(0,0,app.canvas2.width, app.canvas2.height);
                        var w = 10;
                    for (var i = 0; i < volums.length; i++) {
                            app.ctx2.fillStyle = "green";
                        var h = 200 * volums[i].buy/max;
                        app.ctx2.fillRect(i*w, 200 - h, w, h);
                        app.ctx2.fillStyle = "rgba(0,0,0,0.2)";
                        var ht = 200 * volums[i].buy_trades/max_trades;
                        app.ctx2.fillRect(i*w  , 200 - ht, w, ht);


                        app.ctx2.fillStyle = "red";
                        var h2 = 200 * volums[i].sell/max;
                        app.ctx2.fillRect(i*w, 200, w, h2);
                        app.ctx2.fillStyle = "rgba(0,0,0,0.2)";
                        var ht2 = 200 * volums[i].sell_trades/max_trades;
                        app.ctx2.fillRect(i*w, 200, w, ht2);

                    }

                    app.ctx2.beginPath();
                    app.ctx2.strokeStyle = "#000000";
                    app.ctx2.moveTo(0,200);
                    app.ctx2.lineWidth = 2;
                    for (var i = 0 ; i < volums_sr.length; i++) {
                            app.ctx2.lineTo(w * i, 400 - 400 * volums_sr[i]);
                        }
                        app.ctx2.stroke();
                        app.ctx2.closePath();
                       
    //                    app.ctx2.beginPath();
    //                    app.ctx2.moveTo(0,200);
    //                    app.ctx2.strokeStyle = "#2eebda";
//                    for (var i = 0 ; i < volums.length; i++) {
//                        app.ctx2.lineTo(i*w + w/2, 400 - (40 + 320*(volums[i].min - min_price)/(max_price-min_price)));            
//                    }
//                    app.ctx2.stroke();
//                    app.ctx2.closePath();
//                    
//                    app.ctx2.beginPath();
//                    app.ctx2.moveTo(0,200);
//                    app.ctx2.strokeStyle = "#2eebda";
//                    for (var i = 0 ; i < volums.length; i++) {
//                        app.ctx2.lineTo(i*w + w/2, 400 - (40 + 320*(volums[i].max - min_price)/(max_price-min_price)));            
//                    }
//                    app.ctx2.stroke();
//                    app.ctx2.closePath();
                    
                    
                    
                    
                    var max_summ = 0;
                    for (var i = 0; i < volums_sr_summ.length; i++) {
                        if (max_summ < volums_sr_summ[i]) {
                            max_summ = volums_sr_summ[i];
                        }
                    }
                    app.ctx2.beginPath();
                    app.ctx2.moveTo(0,200);
                    app.ctx2.strokeStyle = "#c8a600";
                    for (var i = 0 ; i < volums_sr_summ.length; i++) {
                            app.ctx2.lineTo(i * w + w / 2, 400 - (40 + 320 * volums_sr_summ[i] / max_summ));
                        }
                        app.ctx2.stroke();
                        app.ctx2.closePath();
                    },
                getMaxTrade: function () {
                    var buffer = [].concat(app.buffer);
                    if (buffer == 0) {
                        return ;
                    }
                    app.ctx.clearRect(0,0,app.canvas.width, app.canvas.height);
                    app.max = 0;
                    if (buffer.length > 100) {
                            buffer.splice(0, buffer.length - 100);
                        }
                        app.buy_vol = 0;
                        app.sell_vol = 0;
                        app.max_price = 0;
                        app.min_price = 0;
                    for (var i = 0; i < buffer.length; i++) {
                        
                        if (app.max_price < buffer[i].price) {
                            app.max_price = buffer[i].price;
                        }
                        if (app.min_price == 0 || app.min_price > buffer[i].price) {
                            app.min_price = buffer[i].price;
                        }

                        if (buffer[i].side == "Buy") {
                            app.buy_vol += buffer[i].size;
                        } else {
                            app.sell_vol += buffer[i].size;
                        }
                        if (buffer[i].size > app.max) {
                            app.max = buffer[i].size;
                        }
                    }

                    for (var i = 0; i < buffer.length; i++) {
                            app.ctx.beginPath();
                        app.ctx.fillStyle = "#000000";
                        app.ctx.arc(i, 200 - (20 + 160*(buffer[i].price - app.min_price)/(app.max_price-app.min_price)), 1, 0, 2*Math.PI, false);
                        app.ctx.fill();
                    }
                    $('#max-vol').html("Max vol: " + app.max);
                    $('title').html(buffer[buffer.length-1].price);
                    $('#price').html(buffer[buffer.length-1].price);
                    $('#buy_vol').html(app.buy_vol).css('height', 200 * app.buy_vol / (app.buy_vol + app.sell_vol)+"px");
                    $('#sell_vol').html(app.sell_vol).css('height', 200 * app.sell_vol / (app.buy_vol + app.sell_vol)+"px");
                }
            };
             app.init();
        });

        var kindles = {
                            data: [],
            last_kindle_vol: {},
                        canvas: null,
                        ctx: null,
                        orderBookL2: [],
                        lastPositionPrice: 0,
            init: function () {
                            kindles.canvas = document.getElementById("kindles");
                        kindles.canvas.width = kindles.canvas.offsetWidth;
                        kindles.canvas.height = kindles.canvas.offsetHeight;
                        kindles.ctx = kindles.canvas.getContext('2d');
                       
                    },
            drawTrade: function (data) {
                var $wrap = $('#kindles-wrap');
                for (var i = 0; i < data.length; i++) {
                    if (!kindles.last_kindle_vol[data[i].price]) {
                            kindles.last_kindle_vol[data[i].price] = {
                                price: data[i].price,
                                buy: 0,
                                sell: 0
                            }
                        }

                        var $c = $('<div class="orderifly"></div>');
                    if (data[i].side == "Buy") {
                            $c.addClass('buy');
                        kindles.last_kindle_vol[data[i].price].buy += data[i].size;
                    } else {
                            $c.addClass('sell');
                        kindles.last_kindle_vol[data[i].price].sell += data[i].size;
                    }
                    var w = 6 + Math.round(data[i].size/10000)*2;
                    $c.css('width', w + "px").css('height', w + "px");
                    $wrap.append($c);
                    (function ($c) {
                            setTimeout(function () {
                                //$c.css('top', kindles.lastPositionPrice - 10 + Math.random()*20 + "px").css('right', 630 + Math.random()*40 + "px");
                                $c.css('top', 200 + Math.random() * 200 + "px").css('right', 130 + Math.random() * 200 + "px");
                                setTimeout(function () {
                                    $c.remove();
                                }, 3000);
                            }, 30 + (i + 1) * 10);
                        })($c);
                    }
                   
                },
            redraw: function () {
                            kindles.canvas.width = kindles.canvas.offsetWidth;
                        kindles.canvas.height = kindles.canvas.offsetHeight;
                        var max = 0;
                        var min = 0;
                        var data = [].concat(kindles.data);
                        data = data.reverse();
                if (kindles.last_kindle) {
                            data.push(kindles.last_kindle);
                        }
                        var cwidth = kindles.canvas.width * 0.7;
                        var cheight = kindles.canvas.height;
                for (var i = 0; i < data.length; i++) {
                    var k = data[i];
                    if (max < k.high) {
                            max = k.high;
                        }
                    if (max < k.low) {
                            max = k.low;
                        }
                    if (min == 0 || min > k.high) {
                            min = k.high;
                        }
                    if (min == 0 || min > k.low) {
                            min = k.low;
                        }
                    }
                    kindles.ctx.clearRect(0,0,kindles.canvas.width, kindles.canvas.height);
                    var w = 8;
                    var margin = 2;
                    var kw = 1;
                    var m = cheight / (max - min);
                   
                    var r = Math.round(100*(max - min) / 10)/100;
                for (var i = 0; i < 10; i++) {
                            kindles.ctx.fillStyle = "rgba(0,0,0,0.1)";
                        kindles.ctx.fillRect(0, i*r*m , cwidth, 1);
                    }
                   
                for (var i = 0; i < kindles.orderBookL2.length; i++) {
                    if (kindles.orderBookL2[i].side == "Sell"){
                            kindles.ctx.fillStyle = "rgba(250,0,0,1)";
                        } else {
                            kindles.ctx.fillStyle = "rgba(0,255,0,1)";
                        }
                    if (kindles.orderBookL2[i].size >$('#range_levels').val()) {

                            kindles.ctx.fillRect(0, cheight - (kindles.orderBookL2[i].price - min) * m, cwidth, 2);
                        kindles.ctx.font = "normal normal 16px Tahoma";
                        kindles.ctx.textAlign = "start";
                        kindles.ctx.fillText(kindles.orderBookL2[i].price, 10, cheight - (kindles.orderBookL2[i].price-min)*m - 5, 100);
                    }
                }
                if (app.buffer.length) {
                            kindles.ctx.fillStyle = "rgba(0,0,0,1)";
                        kindles.lastPositionPrice = cheight - (app.buffer[app.buffer.length-1].price-min)*m;
                        kindles.ctx.fillRect(cwidth-100, cheight - (app.buffer[app.buffer.length-1].price-min)*m , 150, 5);
                        kindles.ctx.font = "normal normal 22px Tahoma";
                        kindles.ctx.textAlign = "start";
                        kindles.ctx.fillText(app.buffer[app.buffer.length-1].price, cwidth-100, cheight - (app.buffer[app.buffer.length-1].price-min)*m - 5, 100);
                    }
                   
                   
                for (var i = 0; i < data.length; i++) {
                    var o = data[i];
                        var yh = (o.high - min) * m;
                        var yl = (o.low - min) * m;
                        var yo = (o.open - min) * m;
                        var yc = (o.close - min) * m;
                    if (o.open < o.close) {
                            kindles.ctx.fillStyle = "green";
                        kindles.ctx.fillRect(i*(w+margin) + w/2  , cheight - yh*kw - (1-kw)*cheight/2, 1, 1+kw*(yh-yl));
                        kindles.ctx.fillRect(i*(w+margin)  , cheight - yc*kw - (1-kw)*cheight/2, w, 1+kw*(yc-yo));
                    } else {
                            kindles.ctx.fillStyle = "red";
                        kindles.ctx.fillRect(i*(w+margin) + w/2  , cheight - yh*kw - (1-kw)*cheight/2, 1, 1+kw*(yh-yl));
                        kindles.ctx.fillRect(i*(w+margin)  , cheight - yo*kw - (1-kw)*cheight/2, w, 1+kw*(yo-yc));
                    }

                }

                for (var price in kindles.last_kindle_vol) {
                    var o = kindles.last_kindle_vol[price];
                        kindles.ctx.fillStyle = "green";
                        var w = o.buy/10000;
                        kindles.ctx.fillRect(cwidth + 200 - w, cheight - (o.price - min) * m, w, 4);
                        kindles.ctx.fillStyle = "red";
                        var w = o.sell/10000;
                        kindles.ctx.fillRect(cwidth + 200, cheight - (o.price - min) * m, w, 4);
                       
                    }
                   
                }
            };
        $(function () {
                            kindles.init();
                        });
                       
        </script>
                    <div id='price'></div>
                    <div id="max-vol"></div>
                    <div>Тестовая демо версия 1.0 . Планируется много работы. BITMEX XBT_USD 5 min. Автор: А.Селиванов. <a target="_blank" href="https://t.me/avs_selivanov">Telegram</a>
                        Донаты Btc: <span style="font-weight:bold; color: green;">3BMEXQiU8dCinANTCY8BX1CZrU9UxJBG2A</span></div>
                    <div style=' position:relative;'>
                        <div>
                            Ночной режим - <input type="checkbox" id="bgcolor">
            </div>
                            <div id='max_buy_vol'></div>
                            <input id='range_levels' type='range' min='0' max='1000000'> - Отображать ордера выше <span id='range_levels_val'>500 000</span>
                                <div id='kindles-wrap' style="position:relative; display:inline-block;">
                                    <canvas id="kindles"></canvas>
                                </div>
                                <div>
                                    <input id='range_vol' type='range' min='2' max='30'> количество свечей для вычисления среднего - <span id='range_vol_val'>15</span>
            </div>
                                    <div>
                                        <canvas id="volumspermin"></canvas>
                                    </div>
                                    <style>
                                        .orderifly {
                                            position: absolute;
                                        border-radius:40%;
                                        width:15px;
                                        height:15px;
                                        background-color: green;
                                        transition: 0.9s ease;
                                    }
                .orderifly.buy {
                                            background - color: green;
                                        top: 0;
                                        right: 0;
                                    }
                .orderifly.sell {
                                            background - color: red;
                                        top: 0;
                                        right: 400px;
                                    }
                #volumspermin {
                                            border: 1px solid #000;
                                        width: 1600px;
                                        height:400px;
                                    }
                #kindles {

                                            border: 1px solid #000;
                                        width: 1800px;
                                        height:600px;
                                    }
                                   
            </style>

                                </div>

                                <style>
                                    body.night_style {
                                        background - color: #000;
                                    color: #fff;
                                }
            .prototype {
                                        display: none;
                                }
            #stakan .prototype {
                                        display: none;
                                }
            #stakan {
                                        background - color: #f5f5f5;
                                    display: inline-block;
                                    font-size: 9px;
                                    width: 400px;
                                    position: absolute;
                                    right: 0;
                                }
            #stakan .progressbar{
                                        height: 5px;
                                    background-color: green;
                                }
            #stakan .size{
                                        width: 10%;
                                }
            body {

                                        font - family: arial;
                                            }
            #buy_vol, #sell_vol {
                                        text - align: center;
                                    color: #fff;
                                    font-size: 18px;
                                    display: inline-block;
                                    width:100px;
                                }
            #sell-thread, #buy-thread {
                                        position: relative;
                                    height: 100px;
                                    background-color: #ddd;
                                }
            #price {
                                        font - size: 34px;
                                    font-family: arial;
                                }
        </style>
    </body>
</html>
