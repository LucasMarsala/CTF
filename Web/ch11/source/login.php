<html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
        <title>Home</title>
        <link rel="stylesheet" href="assets/bootstrap/css/bootstrap.min.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Montserrat:400,700">
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic">
        <link rel="stylesheet" href="assets/fonts/font-awesome.min.css">
    </head>
    <body>
  <form action="login.php" method="post">
    <input type="text" name="username" value="username">
    <input type="text" name="password" value="password">
    <input type="submit" name="login" value="login">
</form>
</body>
<?php

ini_set("display_errors", "On");
error_reporting(E_ALL | E_STRICT);
$dbhost = "mysql";
$dbuser = "root";
$dbpass = "root";
$db = "ctf";
$conn = mysqli_connect($dbhost,$dbuser,$dbpass,$db);
mysqli_set_charset($conn,"utf8");
$sql = NULL;

if($_SERVER['REQUEST_METHOD'] == "POST")
{
    $username  = $_POST['username'];
    $password = $_POST['password'];
    $sql = "SELECT * FROM `users` WHERE `username` = '$username' AND `password` = '$password';";
    $res = $conn->query($sql);

    if($res && $res->num_rows - 0) {
      $row = $res -> fetch_assoc();
      var_dump($row);
    } else {
      echo "no such user ";
    }
}

// Create token header as a JSON string
$header = json_encode(['typ' => 'JWT', 'alg' => 'HS256']);

// Create token payload as a JSON string

$payload = json_encode(['username' => "user"]);

// Encode Header to Base64Url String
$base64UrlHeader = str_replace(['+', '/', '='], ['-', '_', ''], base64_encode($header));

// Encode Payload to Base64Url String
$base64UrlPayload = str_replace(['+', '/', '='], ['-', '_', ''], base64_encode($payload));

// Create Signature Hash
$signature = hash_hmac('sha256', $base64UrlHeader . "." . $base64UrlPayload, 'TZ@ch2$`pKa6,V6r', true);

// Encode Signature to Base64Url String
$base64UrlSignature = str_replace(['+', '/', '='], ['-', '_', ''], base64_encode($signature));

// Create JWT
$jwt = $base64UrlHeader . "." . $base64UrlPayload . "." . $base64UrlSignature;

// header('jwt:'.$jwt);

setcookie("jwt", $jwt);

if ($_COOKIE["jwt"] == "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VybmFtZSI6Iml0YWthbGEifQ.1qhtR6dVbR07vJ5Ak2bKKf3IkojchOtS2bwQc8AVAKk")
{
    echo "XD+;8s2q";
}
?>
</html>
