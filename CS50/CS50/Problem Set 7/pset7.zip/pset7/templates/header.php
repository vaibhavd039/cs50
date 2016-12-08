<!DOCTYPE html>

<html>

    <head>

        <link href="/css/bootstrap.min.css" rel="stylesheet"/>
        <link href="/css/bootstrap-theme.min.css" rel="stylesheet"/>
        <link href="/css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>C$50 Finance: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>C$50 Finance</title>
        <?php endif ?>

        <script src="/js/jquery-1.11.1.min.js"></script>
        <script src="/js/bootstrap.min.js"></script>
        <script src="/js/scripts.js"></script>

    </head>

    <body>

        <div class="container">

            <div id="top">
                <a href="/"><img alt="C$50 Finance" src="/img/logo.gif"/></a><br/>
                
                <?php if (isset($title) && $title != TITLE_REGISTER && $title != TITLE_LOGIN): ?>
                    <ul class="nav nav-pills" style="display: inline-block;">
                        <li><a href="/">Portfolio</a></li>
                        <li><a href="quote.php">Stock Quote</a></li>
                        <li><a href="buy.php">Buy</a></li>
                        <li><a href="sell.php">Sell</a></li>
                        <li><a href="deposit.php">Deposit Funds</a></li>
                        <li><a href="history.php">History</a></li>
                        <li><a href="logout.php">Log Out</a></li>
                    </ul>
                    <br/>
                <?php endif ?>
                
                <br/>
            </div>

            <div id="middle">