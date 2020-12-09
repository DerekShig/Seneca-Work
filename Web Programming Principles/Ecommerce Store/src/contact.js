window.onload = function() {
  let order = document.querySelector('.orderText');
  let radios = document.getElementsByName('subject');
  radios.forEach(item => {
    item.addEventListener('click', () => {
      if (item.id == 'orderProblem') {
        order.className = '';
        order.querySelector('input').classList.add('input');
        order.querySelector('input').value = '';
      } else {
        order.classList.add('hidden');
      }
    });
  });
}
