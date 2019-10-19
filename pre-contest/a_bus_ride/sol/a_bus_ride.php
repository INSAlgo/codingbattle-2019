<?php

$nbPerson = 0;
$nbSeat = 0;
fscanf(STDIN, "%d\n", $nbPerson);
fscanf(STDIN, "%d\n", $nbSeat);

$res = ceil($nbPerson / $nbSeat);

echo($res);

?>
