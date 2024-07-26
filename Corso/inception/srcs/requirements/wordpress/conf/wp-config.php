define( 'DB_NAME', getenv('WORDPRESS_DB_NAME') );
define( 'DB_USER', getenv('WORDPRESS_DB_USER') );
define( 'DB_PASSWORD', getenv('WORDPRESS_DB_PASSWORD') );
define( 'DB_HOST', getenv('WORDPRESS_DB_HOST') );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

define('AUTH_KEY',         '_z%PUf67IP4ST|eKrk|NvMR@$4^c?dq+iUQsbfZYPnQ~p+`Dyj$^kJ050q#PSJLY');
define('SECURE_AUTH_KEY',  '!0+;QCd2TtxEg,Y<j)>60o=(Rr9p;:Rt&9Qt2-a> Ui{QbEB<S(D+cF95);u#xE.');
define('LOGGED_IN_KEY',    'E|Jgvt_@+[+-+]lqI/NOzb%7|=sjV1bKAe-vITwn|Vg-^a--^%%X+atYz87k|,UD');
define('NONCE_KEY',        'xF=V#=tjczgOo#T+3;A>5x./9R99+F5&: .V74G]+u@j-@UR,1,=Upzsv+<@GU24');
define('AUTH_SALT',        'MrpJdt#1+]I{8YDCS.u W|MnW7NhtHUk)MDf8cYn9gvI5 opi>y?!Q,+||)$m-qd');
define('SECURE_AUTH_SALT', 'g.z.+,eDVIl8Mw{]d|-D9uS:CT{-9LwpG:Z9wm,Uz@N,/|*,;r(ejFX5>nVX%ljB');
define('LOGGED_IN_SALT',   '@T2*M9CKiv|I;+-WHclh|+3:EcZ?3y+D7hX*P+Pfo*;by.ezAOUfS1-7:13L(:|3');
define('NONCE_SALT',       'XVOtVU+tf},Vp@s+F0EyAh8hL3+FF5+g<JqK>Sei!o[jTarskQ,5pqOm1X5&/7W]');

$table_prefix = 'wp_';

define( 'WP_DEBUG', true );

define( 'WP_HOME', `https://${getenv('DOMAIN_NAME')}` );
define( 'WP_SITEURL', `https://${getenv('DOMAIN_NAME')}` );

if ($_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https')
    $_SERVER['HTTPS']='on';

if ( !defined('ABSPATH') )
    define('ABSPATH', dirname(__FILE__) . '/');

require_once(ABSPATH . 'wp-settings.php');
