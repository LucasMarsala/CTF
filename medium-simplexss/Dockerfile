FROM ubuntu:18.04

LABEL maintainer="CHERIEF Yassine <fy_cherief@esi.dz>"
ENV TZ=Africa/Algiers

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone \
    && apt update && DEBIAN_FRONTEND=noninteractive apt install -y apache2 \
    php \
    libapache2-mod-php \
    cron

COPY bot-cron /etc/cron.d/bot-cron
COPY source/comments /var/www/html/comments

RUN chown www-data: /var/www/html/comments && chmod u+w /var/www/html/comments

RUN crontab /etc/cron.d/bot-cron

RUN touch /var/log/apache2/xss-bot.log

CMD cron && tail -f /var/log/apache2/xss-bot.log

ENTRYPOINT service apache2 start && /bin/bash
