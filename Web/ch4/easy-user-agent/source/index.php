<?php
/*if (isset($_GET["str"]) && isset($_GET["rot"])) {
    $rot = intval($_GET["rot"]);
    $str = $_GET["str"];
    $i = 0;
    $new_string = "";
    while ($i < strlen($str)) {
        $new_string .= chr(ord($str[$i]) + $rot);
        $i++;
    }
    echo $new_string;
}*/
//var_dump($_SERVER["HTTP_USER_AGENT"]);
?>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta http-equiv="X-UA-Compatible" content="ie=edge">
        <title>User Agent</title>
    </head>
    <body>
<?php
if ($_SERVER["HTTP_USER_AGENT"] == "admin")
{
    echo "<p>Mot de passe : User_3g3nt_h4cker</p>";
} else {
    echo "<p>Vous n'etes pas sur le navigateur 'admin'</p>";
}
?>
    </body>
</html>
