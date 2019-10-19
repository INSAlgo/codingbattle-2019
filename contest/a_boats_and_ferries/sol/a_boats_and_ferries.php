<?php
fscanf(STDIN, "%d", $p);
fscanf(STDIN, "%d", $b);
fscanf(STDIN, "%d", $f);

echo(max($p - (500 * $f + 4 * $b), 0));
?>
