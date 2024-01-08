

(function ($) {
    $(".contact-form").submit(function (event) {
        event.preventDefault();
        let chatId = "-1001662824812";
        let token = "5161742046:AAFVX7QwBLjP8SY-O9NK_X0fi_YJNcf0CHU";
        // Сообщения формы
        let successSendText = "Сообщение успешно отправлено";
        let errorSendText = "Сообщение не отправлено. Попробуйте еще раз!";
        let requiredFieldsText = "Заполните поля с именем и телефоном";

        const form = document.getElementById('form-contact');
        let name = form.querySelector('[name = "name"]').value;
        let phone = form.querySelector('[name = "phone"]').value;
        let comment = form.querySelector('[name = "comment"]').value;
        let theme = form.querySelector('[name = "theme"]').value;

        let url = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + chatId + "&text=" +
            encodeURIComponent("Клиент: " + name + "\nТелефон: " + phone + "\nОткуда: " + theme + "\nКомментарий: " + comment);

        let oReq = new XMLHttpRequest();
        oReq.open("GET", url, true);
        oReq.send();


        //if (respond === "SUCCESS") {
        $(this).find(".contact-form__message").text(successSendText).css("color", "#21d4bb");
        setTimeout(() => {
            $(this).find(".contact-form__message").text("");
        }, 4000);
        /*} else if (respond === "NOTVALID") {
            message.text(requiredFieldsText).css("color", "#d42121");
            setTimeout(() => {
                message.text("");
            }, 3000);
        } else {
            message.text(errorSendText).css("color", "#d42121");
            setTimeout(() => {
                message.text("");
            }, 4000);
        }
        */

    });
})(jQuery);
