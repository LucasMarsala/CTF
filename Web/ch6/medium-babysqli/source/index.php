<?php
ini_set("display_errors", "On");
error_reporting(E_ALL | E_STRICT);
$dbhost = "mysql";
$dbuser = "root";
$dbpass = "root";
$db = "ctf";
$conn = mysqli_connect($dbhost,$dbuser,$dbpass,$db);
mysqli_set_charset($conn,"utf8");

/*
function   filter($str){
        $black_list = array("union", "select", "or");
        foreach ($black_list as $key) {
            $str = str_replace($key, "", $str);
        }
        return $str;
}
 */

$username = isset($_GET['username'])?$_GET['username']:die('<a href="/?username=admin">login</a>');

$sql = "select * from `users` where  username ='$username'";

echo "SQL: ";
echo $sql;
echo "</br>";
echo "</br>";
$res = $conn->query($sql);

if($res && $res->num_rows > 0) {
        $row = $res -> fetch_assoc();
        var_dump($row);
} else {
    die("no such user");
}
?>
<!-- index.php.bak -->
