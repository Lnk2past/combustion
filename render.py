from contextlib import contextmanager

import holoviews as hv
import numpy as np
import pandas as pd
import panel as pn
import param
from panel.viewable import Viewer

hv.extension('bokeh')

import combustion
from combustion import Flame

flame = Flame()

p1 = combustion.Linear()
p12 = combustion.Spherical()
t1 = combustion.Transform()
t1.add_variation(p1)
t1.add_variation(p12)
t1.color = 0.2

p2 = combustion.Linear()
t2 = combustion.Transform()
t2.add_variation(p2)
t2.color = 0.8

transforms = pn.widgets.Select(name='Transforms', options=[t1, t2] , value=t1)

iterations_slider = pn.widgets.IntSlider(name='Iterations', start=1, end=1000000)


class TransformEditor(Viewer):
    changed = param.Event()

    def __init__(self, tx, **params):
        self.tx = tx
        self.color_slider = pn.widgets.FloatSlider(name='Color', value=tx.color)
        self.a_slider = pn.widgets.FloatSlider(name='a', start=-10.0, end=10.0, value=tx.a)
        self.b_slider = pn.widgets.FloatSlider(name='b', start=-10.0, end=10.0, value=tx.b)
        self.c_slider = pn.widgets.FloatSlider(name='c', start=-10.0, end=10.0, value=tx.c)
        self.d_slider = pn.widgets.FloatSlider(name='d', start=-10.0, end=10.0, value=tx.d)
        self.e_slider = pn.widgets.FloatSlider(name='e', start=-10.0, end=10.0, value=tx.e)
        self.f_slider = pn.widgets.FloatSlider(name='f', start=-10.0, end=10.0, value=tx.f)
        super().__init__(**params)
        self._layout = pn.Column(self.color_slider, self.a_slider, self.b_slider, self.c_slider, self.d_slider, self.e_slider, self.f_slider)

    def __panel__(self):
        return self._layout

    @param.depends('color_slider.value', 'a_slider.value', 'b_slider.value', 'c_slider.value', 'd_slider.value', 'e_slider.value', 'f_slider.value', watch=True)
    def _sync_params(self):
        self.tx.color = self.color_slider.value
        self.tx.a = self.a_slider.value
        self.tx.b = self.b_slider.value
        self.tx.c = self.c_slider.value
        self.tx.d = self.d_slider.value
        self.tx.e = self.e_slider.value
        self.tx.f = self.f_slider.value
        self.param.trigger('changed')

tes = {
    t1: TransformEditor(t1),
    t2: TransformEditor(t2),
}

transform_editor = pn.Row(tes[t1])

@pn.depends(tx=transforms, watch=True)
def select_transform(tx):
    transform_editor.objects = [tes[tx]]

@pn.depends(i=iterations_slider, _1=tes[t1].param.changed, _2=tes[t2].param.changed, watch=True)
def render(i, **_):
    s = flame.compute(i, transforms.options)
    df = pd.DataFrame(s, columns=['x', 'y', 'c', 'a'])
    ascale = np.log(df.a) / df.a
    df.x = df.x * ascale
    df.y = df.y * ascale
    return hv.Points(df, kdims=['x', 'y'], vdims=['c', 'a']).opts(size=1, color='c', alpha=hv.dim('a').norm(), cmap='plasma')

dmap = hv.DynamicMap(render)

pn.Row(pn.Column(iterations_slider, transforms, transform_editor), dmap.opts(height=640, width=640, bgcolor='black')).servable()
